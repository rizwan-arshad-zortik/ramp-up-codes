import grpc
from concurrent import futures
import time
import message_pb2
import message_pb2_grpc

class MessagingServiceServicer(message_pb2_grpc.MessagingServiceServicer):
    def SendMessage(self, request, context):
        print(f"Received message from client: {request.message}")
        return message_pb2.MessageResponse(reply=f"Server received your message: {request.message}")

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    message_pb2_grpc.add_MessagingServiceServicer_to_server(MessagingServiceServicer(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    print("Server started. Listening on port 50051.")
    try:
        while True:
            time.sleep(86400)
    except KeyboardInterrupt:
        server.stop(0)

if __name__ == '__main__':
    serve()
