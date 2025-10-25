if [[ $1 ]]
then
   loopnum=$1
else
   loopnum=10
fi

if [[ $2 ]]
then
   lower=$2
else
   lower=0
fi

if [[ $3 ]]
then
   upper=$3
else
   upper=9999
fi

numrange=$((( $upper - $lower ) + 1 ))

count=0
while [[ $count -lt $loopnum ]]
do
    val=$(($RANDOM % $numrange + $lower ))
    echo "$val "
    let count++
done
