CC := $(CROSS_COMPILE)gcc

TARGET := writer 

SRC := writer.c 
OBJS := writer.o


all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

$(OBJS): $(SRC) 
	$(CC) -c $< -o $@ 

clean:
	rm -f $(OBJS) $(TARGET)

