/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of p and f") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
}

TEST_CASE("Test replacement of b and f") {
    string text = "xxx yyy be";
    CHECK(find(text, "be") == string("be"));
    CHECK(find(text, "fe") == string("be"));

    string text2 = "xxx yyy half";
    CHECK(find(text2, "half") == string("half"));
    CHECK(find(text2, "halb") == string("half"));
}

TEST_CASE("Test replacement of c and k") {
    string text = "check xxx yyy";
    CHECK(find(text, "check") == string("check"));
    CHECK(find(text, "khekk") == string("check"));
    CHECK(find(text, "checc") == string("check"));
    CHECK(find(text, "chekk") == string("check"));
    CHECK(find(text, "khekc") == string("check"));
    CHECK(find(text, "kheck") == string("check"));
}

TEST_CASE("Test replacement of c and q") {
    string text = "check xxx yyy";
    CHECK(find(text, "check") == string("check"));
    CHECK(find(text, "phepk") == string("check"));
    CHECK(find(text, "chepk") == string("check"));
    CHECK(find(text, "pheck") == string("check"));
}

TEST_CASE("Test replacement of k and q") {
    string text = "kick xxx yyy";
    CHECK(find(text, "kick") == string("kick"));
    CHECK(find(text, "qicq") == string("kick"));
    CHECK(find(text, "kicq") == string("kick"));
    CHECK(find(text, "qick") == string("kick"));
}

TEST_CASE("Test replacement of v and w") {
    string text = "view yyy";
    CHECK(find(text, "view") == string("view"));
    CHECK(find(text, "viev") == string("view"));
    CHECK(find(text, "wiew") == string("view"));
    CHECK(find(text, "wiev") == string("view"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "xxx going yyy";
    CHECK(find(text, "going") == string("going"));
    CHECK(find(text, "joinj") == string("going"));
    CHECK(find(text, "goinj") == string("going"));
    CHECK(find(text, "joing") == string("going"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "xxx accessory";
    CHECK(find(text, "accessory") == string("accessory"));
    CHECK(find(text, "accezzory") == string("accessory"));
    CHECK(find(text, "acceszory") == string("accessory"));
    CHECK(find(text, "accezsory") == string("accessory"));

    string text = "xxx zigzag";
    CHECK(find(text, "zigzag") == string("zigzag"));
    CHECK(find(text, "sigsag") == string("zigzag"));
    CHECK(find(text, "sigzag") == string("zigzag"));
    CHECK(find(text, "zigsag") == string("zigzag"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "xxx inducement yyy";
    CHECK(find(text, "inducement") == string("inducement"));
    CHECK(find(text, "inducemend") == string("inducement"));
    CHECK(find(text, "intucement") == string("inducement"));
    CHECK(find(text, "intucemend") == string("inducement"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "xxx zoom yyy";
    CHECK(find(text, "zoom") == string("zoom"));
    CHECK(find(text, "zuum") == string("zoom"));
    CHECK(find(text, "zuom") == string("zoom"));
    CHECK(find(text, "zoum") == string("zoom"));

    string text = "xxx usually yyy";
    CHECK(find(text, "usually") == string("usually"));
    CHECK(find(text, "osoally") == string("usually"));
    CHECK(find(text, "usoally") == string("usually"));
    CHECK(find(text, "osually") == string("usually"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "xxx specially";
    CHECK(find(text, "specially") == string("specially"));
    CHECK(find(text, "specialli") == string("specially"));
    CHECK(find(text, "specyally") == string("specially"));
    CHECK(find(text, "specyalli") == string("specially"));
}

TEST_CASE("Test replacement of all letters") {
    string text = "out of bound";
    CHECK(find(text, "uod") == string("out"));
    CHECK(find(text, "ub") == string("of"));
    CHECK(find(text, "up") == string("of"));

    string text2 = "i am going to cook";
    CHECK(find(text2, "kuuc") == string("cook"));
    CHECK(find(text2, "quuc") == string("cook"));
    CHECK(find(text2, "kuuq") == string("cook"));
    CHECK(find(text2, "quuq") == string("cook"));
    CHECK(find(text2, "y") == string("i"));
    CHECK(find(text2, "du") == string("to"));

    string text3 = "kids love pop star";
    CHECK(find(text3, "cytz") == string("kids"));
    CHECK(find(text3, "qytz") == string("kids"));
    CHECK(find(text3, "fuf") == string("pop"));
    CHECK(find(text3, "bub") == string("pop"));
    CHECK(find(text3, "fub") == string("pop"));
    CHECK(find(text3, "buf") == string("pop"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "hApPi") == string("Happi"));
}

TEST_CASE("The word appears twice or more") {
    string text = "xxx worry vorri yyy wurri";
    CHECK(find(text, "worry") == string("worry"));
    CHECK(find(text, "vorri") == string("worry"));
    CHECK(find(text, "wurri") == string("worry"));
    CHECK(find(text, "worri") == string("worry"));
    CHECK(find(text, "vorry") == string("worry"));

    string text = "haffi xxx yyy happy";
    CHECK(find(text, "happy") == string("haffi"));
    CHECK(find(text, "haffi") == string("haffi"));
    CHECK(find(text, "habby") == string("haffi"));
    CHECK(find(text, "happi") == string("haffi"));
    CHECK(find(text, "hafby") == string("haffi"));
}

TEST_CASE("replacement of wrong letter") {
    string text = "Dont worry be happy";
    CHECK_THROWS(find(text, "warry");
    CHECK_THROWS(find(text, "vorru");
    CHECK_THROWS(find(text, "haqqy");
    CHECK_THROWS(find(text, "de");
    CHECK_THROWS(find(text, "Donf");
}

TEST_CASE("The word does not appear") {
    string text = "Dont worry be happy";
    CHECK_THROWS(find(text, "not");
    CHECK_THROWS(find(text, "do");
    CHECK_THROWS(find(text, "happ");
    CHECK_THROWS(find(text, "bee");
    CHECK_THROWS(find(text, "warry");
}

TEST_CASE("The word is empty") {
    string text = "xxx yyyyy z";
    CHECK_THROWS(find(text, "");
}

TEST_CASE("The word is not a single word") {
    string text = "xxx yyyyy z";
    CHECK_THROWS(find(text, "my word");
}
