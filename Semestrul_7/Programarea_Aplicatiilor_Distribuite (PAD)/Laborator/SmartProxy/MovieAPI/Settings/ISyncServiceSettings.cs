namespace MovieAPI.Settings
{
    public interface ISyncServiceSettings
    {
        string Host { get; set; }
        string UpsertHttpMethod { get; set; }
        string DeleteHttpMethod { get; set; }
    }
}
