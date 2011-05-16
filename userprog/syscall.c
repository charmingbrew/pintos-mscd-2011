#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "threads/synch.h"
#include "threads/vaddr.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void)
{
  lock_init(&filesys_lock);
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f)
{
  uint32_t *stackpointer = f->esp;
  hex_dump( (uintptr_t)12, f->esp, PHYS_BASE-(int)f->esp,true);
  //hex_dump( (uintptr_t)12, stackpointer, PHYS_BASE-(int) stackpointer,true);
  int call_number = *stackpointer;
//  void ** buffer = (void **)(stackpointer + 2);
//  uint32_t *size = stackpointer + 3;
//  lock_acquire(&filesys_lock);
//  printf("%s", *buffer);
//  lock_release(&filesys_lock);
  printf ("system call! %d\n", call_number);
  thread_exit ();
}

//int write (int fd, const void *buffer, unsigned size) {
//  if (fd == 1) {
//      putbuf(buffer, size);
//      return size;
//  }
//  else {
//
//  }
//}
