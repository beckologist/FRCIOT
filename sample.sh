# Save args to variables
myIP=$1
shift
myPort=$1
shift
myKey=$1
shift
m1=$1
shift
m2=$1
shift
m3=$1
shift
m4=$1
shift
m5=$1
shift
m6=$1
shift
m7=$1
shift
m8=$1


#Call the sampling code and pipe to the sending code
./example $m1 $m2 $m3 $m4 $m5 $m6 $m7 $m8 | java -cp ./  ThingworxSend $myIP $myPort $myKey




