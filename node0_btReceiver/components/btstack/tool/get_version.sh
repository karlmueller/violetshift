#!/bin/sh
DIR=`dirname $0`
FILE=$DIR/../platform/daemon/src/btstack_version.h
COMMIT=`git log -1 --pretty=format:%h`
MAJOR=1
MINOR=0
DATE=`date "+%Y-%m-%d_%H:%M:%S"`
printf "// BTstack - btstack_version.h\n" > $FILE
printf "// - generated by %s\n" $0>> $FILE
printf "// - at %s\n" $DATE >>  $FILE
printf "#define BTSTACK_MAJOR %u\n"             $MAJOR >> $FILE
printf "#define BTSTACK_MINOR %u\n"             $MINOR >> $FILE
printf "#define BTSTACK_COMMIT \"%s\"\n"        $COMMIT >> $FILE
printf "#define BTSTACK_VERSION \"%u.%u-%s\"\n" $MAJOR $MINOR $COMMIT >> $FILE
printf "#define BTSTACK_DATE \"%s\"\n"			$DATE >> $FILE
