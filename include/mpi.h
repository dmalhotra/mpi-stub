#ifndef _MPI_STUB_H_
#define _MPI_STUB_H_

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Communicators */
typedef int MPI_Comm;
#define MPI_COMM_WORLD ((MPI_Comm)91)
#define MPI_COMM_SELF  ((MPI_Comm)92)
#define MPI_COMM_NULL  ((MPI_Comm)0)

/* Define MPI_Datatype */
typedef size_t MPI_Datatype;

/* Define native MPI datatypes. */
#define DECLARE_NATIVE_MPI_DATATYPE(MPITYPE, CTYPE) \
  const MPI_Datatype MPITYPE=sizeof(CTYPE);
DECLARE_NATIVE_MPI_DATATYPE(MPI_BYTE              ,char);
DECLARE_NATIVE_MPI_DATATYPE(MPI_CHAR              ,char);
DECLARE_NATIVE_MPI_DATATYPE(MPI_SHORT             ,signed short int);
DECLARE_NATIVE_MPI_DATATYPE(MPI_INT               ,signed int);
DECLARE_NATIVE_MPI_DATATYPE(MPI_LONG              ,signed long int);
DECLARE_NATIVE_MPI_DATATYPE(MPI_LONG_LONG_INT     ,signed long long int);
DECLARE_NATIVE_MPI_DATATYPE(MPI_LONG_LONG         ,signed long long int);
DECLARE_NATIVE_MPI_DATATYPE(MPI_SIGNED_CHAR       ,signed char);
DECLARE_NATIVE_MPI_DATATYPE(MPI_UNSIGNED_CHAR     ,unsigned char);
DECLARE_NATIVE_MPI_DATATYPE(MPI_UNSIGNED_SHORT    ,unsigned short int);
DECLARE_NATIVE_MPI_DATATYPE(MPI_UNSIGNED          ,unsigned int);
DECLARE_NATIVE_MPI_DATATYPE(MPI_UNSIGNED_LONG     ,unsigned long int);
DECLARE_NATIVE_MPI_DATATYPE(MPI_UNSIGNED_LONG_LONG,unsigned long long int);
DECLARE_NATIVE_MPI_DATATYPE(MPI_FLOAT             ,float);
DECLARE_NATIVE_MPI_DATATYPE(MPI_DOUBLE            ,double);
DECLARE_NATIVE_MPI_DATATYPE(MPI_LONG_DOUBLE       ,long double);
DECLARE_NATIVE_MPI_DATATYPE(MPI_WCHAR             ,wchar_t);

/* Define MPI_Op */
typedef int MPI_Op;
#define MPI_SUM ((MPI_Op)0)
#define MPI_MIN ((MPI_Op)0)
#define MPI_MAX ((MPI_Op)0)

typedef void (*MPI_User_function)(void*, void*, int*, MPI_Datatype*);
int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype);
int MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op);
int MPI_Type_commit(MPI_Datatype *datatype);


/* Basic MPI functions */
int MPI_Init( int *argc, char ***argv);
int MPI_Finalize(void);

int MPI_Comm_rank( MPI_Comm comm, int *rank );
int MPI_Comm_size( MPI_Comm comm, int *size );


/* MPI send/recv functions */
typedef int MPI_Request;
typedef int MPI_Status;

int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag,
             MPI_Comm comm, MPI_Status *status);

int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source,
              int tag, MPI_Comm comm, MPI_Request *request);

int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag,
             MPI_Comm comm);

int MPI_Issend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag,
               MPI_Comm comm, MPI_Request *request);

int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 int dest, int sendtag,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 int source, int recvtag,
                 MPI_Comm comm, MPI_Status *status);


/* MPI collectives */
int MPI_Barrier(MPI_Comm comm);

int MPI_Scan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
             MPI_Op op, MPI_Comm comm);

int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root,
              MPI_Comm comm);

int MPI_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
               MPI_Op op, int root, MPI_Comm comm);

int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,
                  MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

int MPI_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype,
                  MPI_Comm comm);

int MPI_Allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                   void *recvbuf, const int *recvcounts, const int *displs,
                   MPI_Datatype recvtype, MPI_Comm comm);

int MPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 MPI_Comm comm);


/* Miscellaneous MPI functions */
int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm);

int MPI_Comm_free(MPI_Comm *comm);

int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);

int MPI_Wait(MPI_Request *request, MPI_Status *status);

int MPI_Waitall(int count, MPI_Request array_of_requests[],
                MPI_Status array_of_statuses[]);

#ifdef __cplusplus
}
#endif

#endif //_MPI_STUB_H_
