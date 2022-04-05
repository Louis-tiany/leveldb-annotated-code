/*
    * File     : my_dbformat.cc
    * Author   : *
    * Mail     : *
    * Creation : 2022年03月22日 星期二 11时29分12秒
*/

#include <iostream>
#include <ostream>
#include <string>
#include "db/dbformat.h"
#include "leveldb/comparator.h"
#include "util/logging.h"
#include <thread>



void showInternalKey() {
    leveldb::Slice userkey("user");
    leveldb::InternalKey key(userkey, 10, leveldb::ValueType::kTypeValue);
    std::cout << key.DebugString() << std::endl;

    leveldb::ParsedInternalKey parseKey;
    leveldb::ParseInternalKey(key.Encode(), &parseKey);
    std::cout << parseKey.DebugString() << std::endl;
}

void showComparator() {

    const leveldb::Comparator *kc = leveldb::BytewiseComparator();

    std::string str = "123hello";
    leveldb::Slice sli = "123world";

    kc->FindShortestSeparator(&str, sli);
    std::cout << str << std::endl;

    str = "123456";
    kc->FindShortSuccessor(&str);
    std::cout << str << std::endl;
}

void internalKeyComparatorTest() {
    leveldb::InternalKeyComparator ikc(leveldb::BytewiseComparator());

}

void parseKey() {
    leveldb::Slice user_key("hello world");
    leveldb::ParsedInternalKey pik(user_key, 1, leveldb::ValueType::kTypeValue);
    std::cout << pik.DebugString() << std::endl;
}

int main(int argc, char *argv[])
{
    std::thread t([](){
        leveldb::BytewiseComparator();
    });
    t.join();
    // std::cout << leveldb::BytewiseComparator() << std::endl;
    parseKey();
    showInternalKey();
    showComparator();
    return 0;
}
