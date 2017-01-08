#ifndef COMPONENTS_H
#define COMPONENTS_H

coords drawCapacitor(coords cC, bool r=false);
coords drawResistor(coords cR, bool r=false);
coords drawTransistor(coords cQ, bool r=false, int terminal=0);
coords drawGround(coords cG);

coords drawResistor(int x, int y, bool r=false);

coords protoResistor(int x, int y, bool r=false);
coords protoResistor(coords Cr, bool r=false);

#endif
