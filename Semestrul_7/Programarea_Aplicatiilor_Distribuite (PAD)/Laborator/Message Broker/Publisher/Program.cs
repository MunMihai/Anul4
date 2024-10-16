using Common;
using Newtonsoft.Json;
using System.Text;

namespace Publisher
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Publisher");

            var publisherSocket = new PublisherSocket();
            publisherSocket.Connect(Settings.BROCKER_IP, Settings.BROCKER_PORT);

            if (publisherSocket.IsConnected)
            {
                while (true)
                {
                    var payload = new Payload();

                    Console.Write("Enter the topic: ");
                    payload.Topic = Console.ReadLine().ToLower();

                    Console.Write("Enter the message: ");
                    payload.Message = Console.ReadLine();

                    PayloadHandler.Handle(payload, publisherSocket);
                }
            }

            Console.ReadKey();
        }
    }
}
