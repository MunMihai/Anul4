using Common;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Publisher
{
    class PayloadHandler
    {
        public static void Handle(Payload payload, PublisherSocket publisherSocket)
        {
            var payloadString = JsonConvert.SerializeObject(payload);
            byte[] data = Encoding.UTF8.GetBytes(payloadString);

            publisherSocket.Send(data);
        }
    }
}
