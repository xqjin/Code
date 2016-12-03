# The script to build the deom given by the google-protocol-buffer

protoc -I . --cpp_out=.  addressbook.proto

g++ -I /usr/local/include/ -I . -L /usr/local/lib -lprotobuf -lpthread write.cpp addressbook.pb.cc -o write.pb
g++ -I /usr/local/include/ -I . -L /usr/local/lib -lprotobuf -lpthread read.cpp addressbook.pb.cc -o read.pb
