#include "User.h"
#include "MakeSockert.h"

int MakeSockert()
{
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_file_descriptor == -1) {
        cout << "Creation of Socket failed!" << endl;
        return socket_file_descriptor;
    }
    serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddress.sin_port = htons(PORT);
    serveraddress.sin_family = AF_INET;
    connection = connect(socket_file_descriptor, (struct sockaddr*)&serveraddress, sizeof(serveraddress));
    if (connection == -1) {
        cout << "Connection with the server failed.!" << endl;
        return connection;
    }
};
void GetLogAndPass(vector<Person>& A) 
{
    string email;
    string Password;
    cout << "Client is waiting email and Password from Server" << endl;
    std::string output_Log(MESSAGE_LENGTH, 0);
    read(socket_file_descriptor, &output_Log[0], MESSAGE_LENGTH - 1);

    string Buffer_Log;
    for (int i = 0; i < MESSAGE_LENGTH; i++) 
    {

        if ((int)output_Log[i] != 0) {
            cout << output_Log[i] << " ";
            email.push_back((char)output_Log[i]);
        }
        else {
            break;
        };
    }; cout << endl;
    cout << endl;
    std::string output_Pass(MESSAGE_LENGTH, 0);
    read(socket_file_descriptor, &output_Pass[0], MESSAGE_LENGTH - 1);
    for (int i = 0; i < MESSAGE_LENGTH; i++) 
    {

        if ((int)output_Pass[i] != 0) {
            cout << output_Pass[i] << " ";
            Password.push_back((char)output_Pass[i]);
        }
        else {
            break;
        };
    }; cout << endl;

    
    cout << endl;
    cout << "Password received from client: " << Password << endl;


    A.emplace_back(email, Password);
};
void GetMessage(vector<Person::Chat>& B)
{
    cout << "Wait message" << endl;
    string Sender;
    string Receiver;
    string Message;
    std::string output_Sender(MESSAGE_LENGTH, 0);
    read(socket_file_descriptor, &output_Sender[0], MESSAGE_LENGTH - 1);

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
    read(socket_file_descriptor, &output_Receiver[0], MESSAGE_LENGTH - 1);

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
    read(socket_file_descriptor, &output_Message[0], MESSAGE_LENGTH - 1);

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
    ssize_t bytes = write(socket_file_descriptor, message.c_str(), message.size());
    if (bytes >= 0) {
    };
    cout << endl;
};

