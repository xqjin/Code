#include <iostream>
#include <json/json.h>

int write_json(std::string& json_str) {
    using namespace std;
    Json::Value root;
    Json::Value array_obj;
    Json::Value item;

    item["name"] = "jinxiaoqiang";
    item["age"] = 27;
    item["length"] = 0.172;
    array_obj.append(item);
    root["persons"] = array_obj;

    string out = Json::FastWriter().write(root);
    cout << out << endl;
    out = root.toStyledString();
    cout << out << endl;
    json_str = out;
}

int read_json(const std::string& json_str) {
   using namespace std;
   Json::Value root;
   if (0 != Json::Reader().parse(json_str, root)) {
       cout << "parse error of " << json_str << endl;
   }

   cout << root.isObject() << endl;
   if (root.isMember("persons") && root["persons"].isArray()) {
       Json::Value persons = root["persons"];
       for (unsigned i = 0; i < persons.size(); i++) {
           Json::Value person = persons[i];
           if (person.isMember("name") && person["name"].isString()) {
               string name = person["name"].asString();
               cout << "name: " << name << endl;
           }

           if (person.isMember("name") && person["name"].type() == Json::stringValue ) {
               string name = person["name"].asString();
               cout << "name: " << name << endl;
           }

           if (person.isMember("length") && person["length"].isNumeric()) {
               double length_d = person["length"].asDouble();
               int length_i = person["length"].asInt();
               cout << "lenght_d: " << length_d << endl;
               cout << "lenght_i: " << length_i << endl;
           }

           if (person.isMember("length") && person["length"].type() == Json::realValue) {
               double length_d = person["length"].asDouble();
               int length_i = person["length"].asInt();
               cout << "lenght_d: " << length_d << endl;
               cout << "lenght_i: " << length_i << endl;
           }
       }
   }
}

int main() {
    using namespace std;
    std::string json_str;
    write_json(json_str);
    read_json(json_str);
    return 0;
}
