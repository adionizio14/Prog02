#1/bin.bash

# initialize path and extension variables from arguments
path="$1"
ext="$2"

#print out first statement
echo "Looking for files with extension .$ext in folder:" &&
echo "  $path"

count=0

# loop through the path
for file in "$path"/*;
do
  # get filename and extension
  filename="${file##*/}"
  extension="${filename##*.}"
  # if the file extension is the same up the count
  if [[ "$ext" == "$extension" ]] ;
  then
    count=$(($count + 1))
  fi
done

# print the number of files found
if [[ $count == 0 ]];
then
  echo "No file found."
else
  if [[ $count > 1 ]];
  then
  echo "$count files found:"
  else
    echo "$count file found:"
  fi
fi

# re-loop and print the files
for file in "$path"/*;
do
  filename="${file##*/}"
  extension="${filename##*.}"
  if [[ "$ext" == "$extension" ]] ;
  then
    echo "  $filename"
  fi
done