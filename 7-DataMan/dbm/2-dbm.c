#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <gdbm-ndbm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DBM_FILE "/tmp/dbm_test2"
#define MAX 5
struct stu{
	char name[16];
	int id;
	int age;
};

char *name[MAX]={"GG","JJ","MM","DD","VV"
};

int main ( int argc, char *argv[] )
{
	DBM *dbm_fd;
	datum key_datum,data_datum;
	int i,ret;
	struct stu a[MAX],b;

	dbm_fd = dbm_open(DBM_FILE, O_RDWR|O_CREAT,0666);
	if(!dbm_fd){
		perror("open dbm failed");
		exit(2);
	}
	
	for(i=0;i<MAX;i++){
		strcpy(a[i].name ,name[i]);
		a[i].id=i+23;
		a[i].age=i+10;
	}

	char buf[64];
	for(i=0;i<MAX;i++){
		sprintf(buf,"%c%d%d",a[i].name[0],a[i].id, a[i].age);
		key_datum.dptr = (void *)buf;
		key_datum.dsize = strlen(buf);
		data_datum.dptr = (void *)&a[i];
		data_datum.dsize = sizeof(struct stu);
		ret = dbm_store(dbm_fd,key_datum,data_datum,DBM_REPLACE);
		if(ret != 0){
			perror("dbm_store failed");
			exit(2);
		}
	}

	//read from dbm
	sprintf(buf,"%c%d%d",a[3].name[0], a[3].id, a[3].age);
	key_datum.dptr = buf;;
	key_datum.dsize = strlen(buf);
	data_datum = dbm_fetch(dbm_fd, key_datum);
	if(data_datum.dptr){
		printf ( "dbm_fetch  ok\n" );
		memcpy(&b, data_datum.dptr, data_datum.dsize);
		printf ( "%s %d %d\n",b.name, b.id, b.age );
	}else{
		printf ( "dbm_fetch failed\n" );
	}

	//scanf dbm
	for(key_datum = dbm_firstkey(dbm_fd);
			key_datum.dptr;
			key_datum = dbm_nextkey(dbm_fd)){
		data_datum = dbm_fetch(dbm_fd, key_datum);

	if(data_datum.dptr){
		printf ( "dbm_fetch  ok\n" );
		memcpy(&b, data_datum.dptr, data_datum.dsize);
		printf ( "%s %d %d\n",b.name, b.id, b.age );
	}else{
		printf ( "dbm_fetch failed\n" );
	}

	}
	return 0;
}
