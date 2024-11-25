
using Common.Models;
using Microsoft.Extensions.Options;
using MovieAPI.Repositories;
using MovieAPI.Services;
using MovieAPI.Settings;

namespace MovieAPI
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);

            // Add services to the container.
            builder.Services.AddHttpContextAccessor(); 

            builder.Services.Configure<MongoDbSettings>(builder.Configuration.GetSection("MongoDbSettings"));
            builder.Services.Configure<SyncServiceSettings>(builder.Configuration.GetSection("SyncServiceSettings"));

            builder.Services.AddSingleton<IMongoDbSettings>(provider =>
                provider.GetRequiredService<IOptions<MongoDbSettings>>().Value);
            builder.Services.AddSingleton<ISyncServiceSettings>(provider =>
                provider.GetRequiredService<IOptions<SyncServiceSettings>>().Value);

            builder.Services.AddScoped<IMongoRepository<Movie>, MongoRepository<Movie>>();
            builder.Services.AddScoped<ISyncService<Movie>, SyncService<Movie>>();

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
