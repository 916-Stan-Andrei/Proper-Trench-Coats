#include "DynamicVector.h"

void test_dynamic_vector()
{
    DynamicVector<int> v;
    v.addItem(10);
    v.addItem(25);
    v.addItem(5);
    assert(v.getElement(0) == 10);
    assert(v.getElement(1) == 25);
    assert(v.getElement(2) == 5);
    assert(v.getSize() == 3);
    v.deleteItem(1);
    assert(v.getSize() == 2);
    v.updateItem(1, 100);
    assert(v.getElement(1) == 100);
}
