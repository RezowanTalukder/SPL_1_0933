#include <stdio.h>
#include "HexDump02.h"



int main() {
  int data, i, PktLength;
  unsigned char *pkt, PacketData[2048];

  // Get PCAP Global Header
  for (i=0; i<24; i++) {
    data = getchar();
    if (data == EOF ) {
      putchar('\n');
      return 0;
    }
    PacketData[i]=data & 0xFF;
  }
 
  printf("\nPCAP Global Header:\n");
  pkt = PacketData;
  for (i=0; i<24; i++) {
    PrintHex(*pkt++,i);
  }
  putchar('\n');

  // Get PCAP Record Header
  for (i=0; i<16; i++) {
    data = getchar();
    if (data == EOF ) {
      putchar('\n');
      return 0;
    }
    PacketData[i]=data & 0xFF;
  }
 
  printf("\nPCAP Record Header:\n");
  pkt = PacketData;
  for (i=0; i<16; i++) {
    PrintHex(*pkt++,i);
  }
  putchar('\n');


  pkt = PacketData;
  PktLength = *((unsigned int *)(pkt+8) ); 


  // Get Packet 
  for (i=0; i<PktLength; i++) {
    data = getchar();
    if (data == EOF ) {
      putchar('\n');
      return 0;
    }
    PacketData[i]=data & 0xFF;
  }
 
  printf("\nPacket Data:\n");
  pkt = PacketData;
  for (i=0; i<PktLength; i++) {
    PrintHex(*pkt++,i);
  }
  putchar('\n');

  return 0;
}


