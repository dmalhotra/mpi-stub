#include <mpi.h>
#include <string.h>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

int MPI_Init( int *argc, char ***argv) {return 0;};
int MPI_Init_thread( int *argc, char ***argv, int required, int *provided ) {
  (*provided) = required;
  return 0;
};
int MPI_Finalize(void) {return 0;};

MPI_Comm MPI_Comm_f2c(MPI_Fint comm) {return comm;};

int MPI_Comm_rank( MPI_Comm comm, int *rank ){ *rank=0; return 0;}
int MPI_Comm_size( MPI_Comm comm, int *size ){ *size=1; return 0;}

int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype){
  newtype[0]=oldtype*count;
  return 0;
}
int MPI_Op_create(MPI_User_function user_fn, int commute, MPI_Op *op){
  op[0]=0;
  return 0;
}
int MPI_Type_commit(MPI_Datatype *datatype){
  return 0;
}

void* mpi_recv_buff_ptr=NULL;

int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag,
             MPI_Comm comm, MPI_Status *status){
  assert(!mpi_recv_buff_ptr);
  mpi_recv_buff_ptr=buf;
  return 0;
}

int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source,
              int tag, MPI_Comm comm, MPI_Request *request){
  assert(!mpi_recv_buff_ptr);
  mpi_recv_buff_ptr=buf;
  return 0;
}

int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag,
             MPI_Comm comm){
  assert(mpi_recv_buff_ptr);
  memcpy(mpi_recv_buff_ptr, buf, count*datatype);
  mpi_recv_buff_ptr=NULL;
  return 0;
}

int MPI_Issend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag,
               MPI_Comm comm, MPI_Request *request){
  assert(mpi_recv_buff_ptr);
  memcpy(mpi_recv_buff_ptr, buf, count*datatype);
  mpi_recv_buff_ptr=NULL;
  return 0;
}

int MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag,
               MPI_Comm comm, MPI_Request *request){
  assert(mpi_recv_buff_ptr);
  memcpy(mpi_recv_buff_ptr, buf, count*datatype);
  mpi_recv_buff_ptr=NULL;
  return 0;
}

int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 int dest, int sendtag,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 int source, int recvtag,
                 MPI_Comm comm, MPI_Status *status){
  memcpy(recvbuf, sendbuf, sendcount*sendtype);
  return 0;
}

int MPI_Scan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
             MPI_Op op, MPI_Comm comm){
  memcpy(recvbuf, sendbuf, count*datatype);
  return 0;
}

int MPI_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
               MPI_Op op, int root, MPI_Comm comm){
  memcpy(recvbuf, sendbuf, count*datatype);
  return 0;
}

int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,
                  MPI_Datatype datatype, MPI_Op op, MPI_Comm comm){
  memcpy(recvbuf, sendbuf, count*datatype);
  return 0;
}

int MPI_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype,
                  MPI_Comm comm){
  memcpy(recvbuf, sendbuf, sendcount*sendtype);
  return 0;
}

int MPI_Allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                   void *recvbuf, const int *recvcounts, const int *displs,
                   MPI_Datatype recvtype, MPI_Comm comm){
  memcpy(((char*)recvbuf)+displs[0]*recvtype, sendbuf, sendcount*sendtype);
  return 0;
}

int MPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 MPI_Comm comm){
  memcpy(recvbuf, sendbuf, sendcount*sendtype);
  return 0;
}

int MPI_Alltoallv(const void *sendbuf, const int *sendcounts,
                  const int *sdispls, MPI_Datatype sendtype, void *recvbuf,
                  const int *recvcounts, const int *rdispls, MPI_Datatype recvtype,
                  MPI_Comm comm) {
  memcpy(((char*)recvbuf)+rdispls[0]*recvtype, ((char*)sendbuf)+sdispls[0]*sendtype, sendcounts[0]*sendtype);
  return 0;
}

int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm){
  return 0;
}

int MPI_Comm_free(MPI_Comm *comm){
  return 0;
}

int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm){
  return 0;
}

int MPI_Wait(MPI_Request *request, MPI_Status *status){
  return 0;
}

int MPI_Waitall(int count, MPI_Request array_of_requests[],
                MPI_Status array_of_statuses[]){
  return 0;
}

int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root,
              MPI_Comm comm){
  return 0;
}

int MPI_Barrier(MPI_Comm comm){
  return 0;
}

#ifdef __cplusplus
}
#endif
