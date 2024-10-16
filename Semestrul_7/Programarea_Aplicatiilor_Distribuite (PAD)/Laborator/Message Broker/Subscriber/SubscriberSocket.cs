using Common;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Channels;


namespace Subscriber
{
    class SubscriberSocket
    {
        private Socket _socket;
        private String _topic;

        public SubscriberSocket(String topic)
        {
            _topic = topic;
            _socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        }

        public void Connect(string ipAddress, int port)
        {
            _socket.BeginConnect(new IPEndPoint(IPAddress.Parse(ipAddress), port), ConnectedCallback, null);
            Console.WriteLine("Waiting for connection...");
        }

        private void ConnectedCallback(IAsyncResult asyncResult)
        {
            ConnectionInfo connection = new ConnectionInfo();

            try
            {
                connection.Socket = _socket;
                if (_socket.Connected)
                {
                    Console.WriteLine("Subscriber connect to broker.");
                    Subscribe();
                    Receive(connection);
                }
                else
                {
                    Console.WriteLine("Subscriber could not connect to broker!");
                    Close(connection);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine($"Subscriber could not connected to broker! {e.Message}");
            }
        }

        private void Receive(ConnectionInfo connection)
        {
            try
            {
                if (connection.Socket.Connected)
                {
                    connection.Socket.BeginReceive(connection.Buffer, 0, connection.Buffer.Length,
                        SocketFlags.None, ReceiveCallback, connection);
                }
                else
                {
                    Close(connection);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine($"{e.Message}");
                Close(connection);
            }
        }

        private void ReceiveCallback(IAsyncResult asyncResult)
        {
            ConnectionInfo connectionInfo = asyncResult.AsyncState as ConnectionInfo;

            try
            {
                SocketError response;
                int buffsize = _socket.EndReceive(asyncResult, out response);

                if (response == SocketError.Success)
                {
                    byte[] payloadBytes = new byte[buffsize];

                    Array.Copy(connectionInfo.Buffer, payloadBytes, payloadBytes.Length);

                    PayloadHandler.Handle(payloadBytes);
                }
                else
                {
                    Console.WriteLine($"Can't receive data from broker.");
                }
            }
            catch (Exception e)
            {
                Console.WriteLine($"Can't receive data from broker. {e.Message}");
            }
            finally
            {
                Receive(connectionInfo);
            }
        }

        private static void Close(ConnectionInfo connection)
        {
            connection.Socket.Close();
            Console.WriteLine("Press any key to exit...");

        }

        private void Subscribe()
        {
            var data = Encoding.UTF8.GetBytes(Settings.SUBSCRIBE_STRING + _topic);
            Send(data);
        }

        private void Send(byte[] data)
        {
            try
            {
                _socket.Send(data);
            }
            catch (Exception e)
            {
                Console.WriteLine($"Could not send data {e.Message}");
            }
        }
    }
}
