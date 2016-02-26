/* 
 * Author: Makhtar Diouf
 * $Id$
 * Extract Abstract Syntax Notation code from 3GPP RRC specs
 * See the sample EUTRA-RRC36331.txt  (ASN.1)
 * February 24, 2016, 10:16 PM
 * g++ -std=c++11 -g -Wall -o parse_asn1 parse_asn1.cpp
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {

    string from, to;
    if (argc < 2) {
        cout << "\nEnter txt SOURCE filename: ";
        cin >> from;
    } else {
        from = argv[1];
    }
    to = from + ".asn";

    try {
        ifstream src{from};
        if (!src) {
            throw runtime_error("Input file could not be read ");
        }

        clog << "Parsing ASN.1 code from " + from + " to " + to + "\n";       
        ofstream target{to};
      //  target << "EUTRA-RRC-Definitions DEFINITIONS AUTOMATIC TAGS ::=\n";
      //  target << "\nBEGIN\n";
        string s;
        while (!src.eof()) {
          std::getline(src, s);
            // Skip until we reach ASN code
            if (s == "-- ASN1START") {
                while (!src.eof()) {
                    std::getline(src, s);                    
                    clog << s << "\n";
                    // Stop writing to target asn file
                    if (s == "-- ASN1STOP") {
                        break;
                    }
                    target << s << "\n";
                }
            }

        }
     //   target << "\nEND\n";
        clog << " done.\n";
        return (!src.eof() && !target); // return error state
        
    } catch (runtime_error ex) {
        std::cerr << "Error: " << ex.what() << " " << __FILE__ << ":" << __LINE__ << "\n";
        return EXIT_FAILURE;
    }
}

