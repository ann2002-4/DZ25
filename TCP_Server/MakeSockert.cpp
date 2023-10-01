#include "User.h"
#include "MakeSockert.h"

int MakeSockert()
{
    sockert_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (sockert_file_descriptor == -1) {
        cout << "Socket creation failed.!" << endl;
        return sockert_file_descriptor;
    };
    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddress.sin_port = htons(PORT);
    serveraddress.sin_family = AF_INET;
    bind_status = bind(sockert_file_descriptor, (struct sockaddr*)&serveraddress,
        sizeof(serveraddress));
    if (bind_status == -1) {
        cout << "Socket binding failed.!" << endl;
        return bind_status;
    }
    connection_status = listen(sockert_file_descriptor, 5);
    if (connection_status == -1) {
        cout << "Socket is unable to listen for new connections.!" << endl;
        return connection_status;
    }
    else {
        cout << "Server is listening for new connection: " << endl;
    }
    length = sizeof(client);
    connection = accept(sockert_file_descriptor, (struct sockaddr*)&client, &length);
    if (connection == -1) {
        cout << "Server is unable to accept the data from client.!" << endl;
        return connection;
    };
};
void GetLogAndPass(vector<Person>& A) 
{
    string email;
    string Password;
    std::string output_Log(MESSAGE_LENGTH, 0);
    read(connection, &output_Log[0], MESSAGE_LENGTH - 1);

    for (int i = 0; i < MESSAGE_LENGTH; i++) 
    {

        if ((int)output_Log[i] != 0) {
            email.push_back((char)output_Log[i]);
        }
        else {
            break;
        };
    }; cout << endl;
    cout << endl;
    std::string output_Pass(MESSAGE_LENGTH, 0);
    read(connection, &output_Pass[0], MESSAGE_LENGTH - 1);
  
    for (int i = 0; i < MESSAGE_LENGTH; i++) 
    {

        if ((int)output_Pass[i] != 0) {
            Password.push_back((char)output_Pass[i]);
        }
        else {
            break;
        };
    }; cout << endl;
    cout << endl;
    A.emplace_back(email, Password); 
};
void GetMessage(vector<Person::Chat>& B)
{
    cout << "Wait message" << endl;
    string Sender;
    string Receiver;
    string Message;
    std::string output_Sender(MESSAGE_LENGTH, 0);
    read(connection, &output_Sender[0], MESSAGE_LENGTH - 1);

    for (int i = 0; i < MESSAGE_LENGTH; i++) 
    {

        if ((int)output_Sender[i] != 0) {
            Sender.push_back((char)output_Sender[i]);
        }
        else
        {
            break;
        };
    }; cout << endl;
    cout << "Sender received from client: " << Sender << endl;

    std::string output_Receiver(MESSAGE_LENGTH, 0);
    read(connection, &output_Receiver[0], MESSAGE_LENGTH - 1);

    for (int i = 0; i < MESSAGE_LENGTH; i++) 
    {

        if ((int)output_Receiver[i] != 0) {
            Receiver.push_back((char)output_Receiver[i]);
        }
        else {
            break;
        };
        }; cout << endl;
        cout << "Receiver received from client: " << Receiver << endl;

        std::string output_Message(MESSAGE_LENGTH, 0);
        read(connection, &output_Message[0], MESSAGE_LENGTH - 1);

        for (int i = 0; i < MESSAGE_LENGTH; i++) 
        {

            if ((int)output_Message[i] != 0) {
                Message.push_back((char)output_Message[i]);
            }
            else {
                break;
            };
        }; cout << endl;
        cout << "Message received from client: " << Message << endl;

        B.emplace_back(Sender, Receiver, Message);
};

void Send_Message(string message)
{
    ssize_t bytes = write(connection, message.c_str(), message.size());
    if (bytes >= 0) {
    };
    cout << endl;
};
