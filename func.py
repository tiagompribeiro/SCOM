#!/usr/bin/python
print "Content-type: text/html \n\n"

import cgi
form = cgi.FieldStorage()
def sumOfDigitsFrom1ToN(n) :

    result = 0   # initialize result
    n = int (n)
    # One by one compute sum of digits
    # in every number from 1 to n
    for x in range(1, n+1) :
        result = result + sumOfDigits(x)

    return result

# A utility function to compute sum of
# digits in a given number x
def sumOfDigits(x) :
    sum = 0
    while (x != 0) :
        sum = sum + x % 10
        x   = x // 10

    return sum


# /usr/lib/cgi-bin/
print "<html>"

print "<title> SCOM - LAB1 </title>"

print "<body>"
print "<h3>"
print "Number inserted : "
print form.getfirst('fnumber')
print "</h3>"
print "<body>"
print "<h3>"
print "Result : "
print sumOfDigitsFrom1ToN(form.getfirst('fnumber'))
print "</h3>"
print "</body>"

print "</html>"
