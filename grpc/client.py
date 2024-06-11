import grpc
import message_pb2
import message_pb2_grpc

def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = message_pb2_grpc.MessagingServiceStub(channel)
        response = stub.SendMessage(message_pb2.MessageRequest(message='Hello, Server!'))
        print(f"Client received: {response.reply}")

if __name__ == '__main__':
    run()
