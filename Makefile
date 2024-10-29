CC = gcc -static -fPIC
CXX = g++ -static -fPIC
AR = ar rcu 

RM = rm -f
MKDIRS = mkdir -p

LIBDIR = ./lib
SRCDIR = ./src
INCDIR = ./include

TARGET = $(LIBDIR)/libmpi.a

all : $(TARGET)

$(LIBDIR)/lib%.a: $(SRCDIR)/%.o
	-@$(MKDIRS) $(dir $@)
	$(AR) $@ $^

%.o : %.cpp
	-@$(MKDIRS) $(dir $@)
	$(CC) -I$(INCDIR) -c $^ -o $@

clean: 
	$(RM) -f *~ */*~ $(SRCDIR)/*.o
	$(RM) -f $(TARGET)
