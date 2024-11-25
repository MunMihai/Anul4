
using Microsoft.Extensions.Options;
using SyncNode.Servises;
using SyncNode.Settings;

namespace SyncNode
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);

            // Add services to the container.
            builder.Services.Configure<MovieAPISettings>(builder.Configuration.GetSection("MovieAPISettings"));
            builder.Services.AddSingleton<IMovieAPISettings>(provider =>
                provider.GetRequiredService<IOptions<MovieAPISettings>>().Value);

            builder.Services.AddSingleton<SyncWorkJobService>();
            builder.Services.AddHostedService(provider => provider.GetService<SyncWorkJobService>());

            builder.Services.AddControllers();
            // Learn more about configuring OpenAPI at https://aka.ms/aspnet/openapi
            builder.Services.AddOpenApi();

            var app = builder.Build();

            // Configure the HTTP request pipeline.
            if (app.Environment.IsDevelopment())
            {
                app.MapOpenApi();
            }

            app.UseAuthorization();


            app.MapControllers();

            app.Run();
        }
    }
}
