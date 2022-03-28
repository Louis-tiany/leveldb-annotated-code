/*
    * File     : my_dbformat.cc
    * Author   : *
    * Mail     : *
    * Creation : 2022年03月22日 星期二 11时29分12秒
*/

#include <iostream>
#include <string>
#include "db/dbformat.h"
#include "leveldb/comparator.h"
#include "util/logging.h"
#include <thread>



void* showInternalKey(void *arg) {
    leveldb::Slice userkey("user");
    leveldb::InternalKey key(userkey, 10, leveldb::ValueType::kTypeValue);
    std::cout << key.DebugString() << std::endl;
    std::string rep = key.Encode().data();
    for(char re : rep) {
        std::cout << static_cast<int>(re) << "\t";
    }
    std::cout << std::endl;

    std::cout << std::string(key.user_key().data()) << std::endl;

    std::cout << "===============" << std::endl;

    leveldb::ParsedInternalKey parseKey;
    leveldb::ParseInternalKey(key.Encode(), &parseKey);
    std::cout << parseKey.DebugString() << std::endl;
    return nullptr;
}

void showComparator() {

    std::cout << "===============" << std::endl;
    std::cout << leveldb::BytewiseComparator() << std::endl;
    auto kc = leveldb::BytewiseComparator();

    leveldb::Slice a("abcdefghijklmn12");
    leveldb::Slice b("bcdefghijklmno13");

    std::string x = "helloworld";
    b = "hellozoomer";

    kc->FindShortestSeparator(&x, b);
    std::cout << x << std::endl;

    x = "helloworld";
    kc->FindShortSuccessor(&x);
    std::cout << x << std::endl;
}

void internalKeyComparatorTest() {
    leveldb::InternalKeyComparator ikc(leveldb::BytewiseComparator());


}




int main(int argc, char *argv[])
{
    std::thread t([](){
        leveldb::BytewiseComparator();
    });
    t.join();
    // std::cout << leveldb::BytewiseComparator() << std::endl;
    showInternalKey(NULL);
    showComparator();
    return 0;
}
