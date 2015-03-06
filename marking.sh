FILES="clean.sh Makefile.common pipair.mak test1 test2 test3 timeout.sh verify.sh"
cp -R $FILES pi
cd pi
./verify.sh
rm -r $FILES
