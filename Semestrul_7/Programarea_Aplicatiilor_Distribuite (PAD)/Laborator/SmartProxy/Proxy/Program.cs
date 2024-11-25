using Ocelot.DependencyInjection;
using Ocelot.Middleware;
using Ocelot.Cache.CacheManager;


namespace Proxy
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);

            builder.Logging.AddConsole();

            // Add Ocelot services to the DI container
            builder.Configuration.AddJsonFile("ocelot.json");
            builder.Services.AddOcelot().AddCacheManager(x => x.WithDictionaryHandle());

            var app = builder.Build();

            app.MapGet("/", () => "Smart Proxy");

            // Enable Ocelot middleware
            app.UseOcelot().Wait();

            app.Run();
        }
    }
}
