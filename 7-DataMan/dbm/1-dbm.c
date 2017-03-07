#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
//#include <ndbm.h>
#include <gdbm-ndbm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_FILE "/tmp/dbm_test"
struct test_data{
	char misc_name[16];
	int num_id;
	int year;
};
#define MAX 3
int main ( int argc, char *argv[] )
{
	struct test_data a[MAX];
	struct test_data b;
	char buf[32];
	int i,ret;

	datum key_datum,data_datum;
	DBM *dbm_p;
	dbm_p = dbm_open(DB_FILE,O_RDWR|O_CREAT,0666);
	if(!dbm_p){
		perror("failed open data");
		exit(-1);
	}
	memset(a,'\0',sizeof(a));
	strcpy(a[0].misc_name,"GG");
	a[0].num_id=10;
	a[0].year=1997;

	strcpy(a[1].misc_name,"MM");
	a[1].num_id=11;
	a[1].year=1998;

	strcpy(a[2].misc_name,"DD");
	a[2].num_id=12;
	a[2].year=1999;
	
	for(i=0;i<3;i++){
//		sprintf(buf,"%c%d%d",a[i].misc_name[0],a[i].num_id,a[i].year);
		sprintf(buf,"%c%d%d",a[i].misc_name[0], a[i].num_id, a[i].year);
		key_datum.dptr = (void *)buf;
		key_datum.dsize = strlen(buf);
		data_datum.dptr = (void *)&a[i];
		data_datum.dsize = sizeof(struct test_data);
		ret = dbm_store(dbm_p,key_datum,data_datum,DBM_REPLACE);
		if(ret == -1){
			perror("dbm_store failed");
			exit(2);
		}
		memset(buf,'\0',32);
	}

	//read form dbm
	sprintf(buf,"%c%d%d",a[1].misc_name[0],a[1].num_id, a[1].year);
	key_datum.dptr = (void *)buf;
	key_datum.dsize = strlen(buf);
	data_datum = dbm_fetch(dbm_p, key_datum);
	if(data_datum.dptr){
		memcpy(&b,data_datum.dptr,data_datum.dsize);
		printf ( "%s %d %d\n",b.misc_name,b.num_id,b.year );
	}
	else{

		printf ( "fetch failed\n" );
	}
	dbm_close(dbm_p);

	return 0;
}
