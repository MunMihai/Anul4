using Common;

namespace Subscriber
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Subscriber");

            string topic;

            Console.WriteLine("Enter the topic: ");
            topic = Console.ReadLine().ToLower();

            var subscriberSocket = new SubscriberSocket(topic);

            subscriberSocket.Connect(Settings.BROCKER_IP, Settings.BROCKER_PORT);

            Console.ReadLine();
        }
    }
}
