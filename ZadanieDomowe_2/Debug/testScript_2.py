# Author: Michał Nowicki
# Script to test homework
	
from subprocess import Popen, PIPE, STDOUT
import sys

def testCode(testCaseIn, testCaseOut):
	ile = 0;
	for i in range(0,len(testCaseIn)):
	
		p = Popen(['zadanieDomowe_2.exe'], stdout=PIPE, stdin=PIPE)
		w = p.communicate(bytes(testCaseIn[i], 'UTF-8'))[0];
		w=w.rstrip();
		w = w.decode('latin-1'); #	w = w.decode('utf-8');  
		print ('Input      : ' + testCaseIn[i]);
		print ('Output     : ' + w);
		print('Correct out: ' + testCaseOut[i]);

		if w == testCaseOut[i]:
			print('    Test ' +str(i)+' - Ok!')
			ile=ile+1;
		else:
			print('    Test ' +str(i)+' - Something is wrong!');
	return ile;
		
		
		
if len(sys.argv) < 2:
    sys.exit('Please add number of task to test, e. g., \'python testScript.py 1\' to test task 1')
else:
	# Homework example1
	if int(sys.argv[1]) == 1:
		testCaseIn = ['1 1 2', '1 1.111 0.889', '1 1.5 0.2', '1 2 4.1', '1 4.2 5.13'] ;
		testCaseOut = ['3.00','2.00', '1.70', '6.10','9.33'] ;
	elif int(sys.argv[1]) == 2:
		testCaseIn = ['2 3 4 5', '2 3 3 3', '2 3.5 2.3 3.5', '2 3 4 6.9', '2 7 6 5'] ;
		testCaseOut = ['12.00 6.00 90.00', '9.00 3.90 60.00', '9.30 3.80 70.82', '13.90 2.01 160.40', '18.00 14.70 78.46'] ;
	elif int(sys.argv[1]) == 3:
		testCaseIn = ['3 3 4 -5', '3 0 0 1', '3 1 2 1', '3 0 1 0', '3 2 5 3'] ;
		testCaseOut = ['-2.12 0.79','brak', '-1.00', '0.00', '-1.50 -1.00'] ;
	elif int(sys.argv[1]) == 4:
		testCaseIn = ['4 3 -1 2 1', '4 5 -1 22 -11 -13 3', '4 1 1', '4 2 0.00 2.00','4 5 1 3 4 11 -20'] ;
		testCaseOut = ['2.00 -1.00 0.67', '22.00 -13.00 0.00', '1.00 1.00 1.00', '2.00 0.00 1.00', '11.00 -20.00 -0.20'] ;
	elif int(sys.argv[1]) == 5:
		testCaseIn = ['5 1', '5 5', '5 6', '5 29', '5 32'] ;
		testCaseOut = ['1.00', '8.00', '13.00', '832040.00', '3524578.00'] ;
	elif int(sys.argv[1]) == 6:
		testCaseIn = ['6 4 1 3 2 0', '6 5 -11 22 1 1 1', '6 1 1', '6 3 3 1 1','6 4 1.11 2.11 1.23 4.21'] ;
		testCaseOut = ['3.00 2.00 1.00 0.00', '22.00 1.00 1.00 1.00 -11.00', '1.00', '3.00 1.00 1.00', '4.21 2.11 1.23 1.11'] ;
	elif int(sys.argv[1]) == 7:
		testCaseIn = ['7 1 1', '7 3 1 + 1 + 2', '7 5 1 + 0 + 0 + 1 + 2', '7 5 1 + 0 / 0 * 1 + 2', '7 3 1 + 3 * 2'] ;
		testCaseOut = ['1.00', '4.00', '4.00', 'blad', '7.00'] ;
	else:
		sys.exit('Wrong task number');
		
	wynik = testCode(testCaseIn, testCaseOut);
	print('----\nProgram works ok for ' + str(wynik) + ' tests out of ' + str(len(testCaseIn)) + '\n----');
		


