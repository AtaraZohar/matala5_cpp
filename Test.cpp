/**
 * A demo program for matala5.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
using namespace itertools;
#define COMMA ,

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {
     int number=5;
     testcase.setname("Test range: ");
        for (int i: range(5,9)){
         testcase.CHECK_EQUAL(i, number); 
         number++;
        }
		
        char answer[]={'a','b','c'} ;
		number=0;
		for (int i: range('a','d')){
         testcase.CHECK_EQUAL(i, answer[number]); 
         number++;
        }

		double number2=3.7;
		for (double j: range(3.7,6.7)){
         testcase.CHECK_EQUAL(j, number2); 
         number2++;
        }

		char answer2[]={'g','o','o','d','b','y','e'} ;
		number=0;
		testcase.setname("Test string: ");
        for (int i: string("goodbye")){
         testcase.CHECK_EQUAL(i, answer2[number]); 
         number++;
        }
         
		 testcase.setname("Test chain: ");
		 int chainChack=1;
     	 for (int i: chain(range(1,5),range(5,8))){
           testcase.CHECK_EQUAL(i, chainChack);
		   chainChack++;
         }


       char chainStr[]={'a','b','c'} ;
		number=0;
		for (int i:chain(range('a','b'), range('b','d'))){
         testcase.CHECK_EQUAL(i, chainStr[number]); 
         number++;
        }

        char chianStr2[]={'a','b','c','d','h','e','l','l','o'};
        number=0;
        for (char i: chain(range('a','e'), string("hello"))){
         testcase.CHECK_EQUAL(i, chianStr2[number]);
         number++;     

        }

    int answer11[]={1,2,3,4} ;
    char answer22[]={'a','b','c','d'} ;
		testcase.setname("Test chain: ");
		int number11=0;
		int number22=0;
		for (auto i: chain(range(1,5), string("abcd"))){
			if(number11<=3){
				testcase.CHECK_EQUAL(i, answer11[number11]);
				number11++;
			}
			else{
               testcase.CHECK_EQUAL(i, answer22[number22]); 
         		number22++;
			}
     }

		testcase.setname("Test zip: ");
	    string answerS[]={"1,w","2,e","3,l","4,c","5,o","6,m","7,e"} ;
		number=0;
        for (auto i: zip(range(1,8), string("welcome"))){
         testcase.CHECK_OUTPUT(i, answerS[number]); 
         number++;
        }

		string answerS1[]={"10,a","11,b","12,c","13,d"} ;
		number=0;
        for (auto i: zip(range(10,14), range('a','e'))){
         testcase.CHECK_OUTPUT(i, answerS1[number]); 
         number++;
        }

		string answerS2[]={"1,b","2,y","3,e","4,b","5,y","6,e"} ;
		number=0;
        for (auto i: zip(range(1,7), string("byebye"))){
         testcase.CHECK_OUTPUT(i, answerS2[number]); 
         number++;
        }

		string answerS3[]={"1,1","2,2","3,3","4,4"} ;
		number=0;
        for (auto i: zip(range(1,4), range(1,4))){
         testcase.CHECK_OUTPUT(i, answerS3[number]); 
         number++;
        }

		testcase.setname("Test product: ");
		string answerSS[]={"1,1","1,2","1,3","2,1","2,2","2,3"} ;
		number=0;
        for (auto i: product(range(1,3), string("123"))){
         testcase.CHECK_OUTPUT(i, answerSS[number]); 
         number++;
        }

		string answerS5[]={"1,a","1,b","1,c","2,a","2,b","2,c"} ;
		number=0;
        for (auto i: product(range(1,3), string("abc"))){
         testcase.CHECK_OUTPUT(i, answerS5[number]); 
         number++;
        }


	testcase.setname("Test powerset: ");
	string powerSetC[]={"{}","{a}","{b}","{a,b}"};
    number=0;
    for (auto subset: powerset(chain(range('a','b'),range('b','c')))){
      testcase.CHECK_OUTPUT(subset, powerSetC[number]);
      number++;
      }

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}