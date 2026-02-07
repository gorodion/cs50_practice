#include <stdio.h>
#include <assert.h>
#include "hashset.h"

void test_hashset_add() {
    printf("Testing hashsetAdd...\n");
    HashSet *set = createHashSet();
    
    // Add some values
    hashsetAdd(set, 10);
    hashsetAdd(set, 20);
    hashsetAdd(set, 30);
    hashsetAdd(set, 110); // Should hash to same bucket as 10
    
    // Check if values are in the set
    assert(hashsetContains(set, 10) == 1);
    assert(hashsetContains(set, 20) == 1);
    assert(hashsetContains(set, 30) == 1);
    assert(hashsetContains(set, 110) == 1);
    
    // Try to add duplicate
    hashsetAdd(set, 10);
    // Should still only have one 10
    assert(hashsetContains(set, 10) == 1);
    
    printf("hashsetAdd test passed!\n");
    freeHashSet(set);
}

void test_hashset_contains() {
    printf("Testing hashsetContains...\n");
    HashSet *set = createHashSet();
    
    // Test empty set
    assert(hashsetContains(set, 5) == 0);
    
    // Add values and test
    hashsetAdd(set, 5);
    assert(hashsetContains(set, 5) == 1);
    assert(hashsetContains(set, 15) == 0); // Different value
    
    // Test negative numbers
    hashsetAdd(set, -10);
    assert(hashsetContains(set, -10) == 1);
    assert(hashsetContains(set, 10) == 0); // Different sign
    
    printf("hashsetContains test passed!\n");
    freeHashSet(set);
}

void test_hashset_remove() {
    printf("Testing hashsetRemove...\n");
    HashSet *set = createHashSet();
    
    // Add values
    hashsetAdd(set, 10);
    hashsetAdd(set, 20);
    hashsetAdd(set, 30);
    
    // Remove existing value
    hashsetRemove(set, 20);
    assert(hashsetContains(set, 10) == 1);
    assert(hashsetContains(set, 20) == 0);
    assert(hashsetContains(set, 30) == 1);
    
    // Try to remove non-existing value
    hashsetRemove(set, 40);
    assert(hashsetContains(set, 10) == 1);
    assert(hashsetContains(set, 30) == 1);
    
    // Remove all values
    hashsetRemove(set, 10);
    hashsetRemove(set, 30);
    assert(hashsetContains(set, 10) == 0);
    assert(hashsetContains(set, 30) == 0);
    
    printf("hashsetRemove test passed!\n");
    freeHashSet(set);
}

void test_hashset_collision() {
    printf("Testing hash collision handling...\n");
    HashSet *set = createHashSet();
    
    // Add values that should collide (same hash)
    hashsetAdd(set, 0);
    hashsetAdd(set, 100);
    hashsetAdd(set, 200);
    hashsetAdd(set, 300);
    
    // All should be in the set
    assert(hashsetContains(set, 0) == 1);
    assert(hashsetContains(set, 100) == 1);
    assert(hashsetContains(set, 200) == 1);
    assert(hashsetContains(set, 300) == 1);
    
    // Remove one and check others remain
    hashsetRemove(set, 200);
    assert(hashsetContains(set, 0) == 1);
    assert(hashsetContains(set, 100) == 1);
    assert(hashsetContains(set, 200) == 0);
    assert(hashsetContains(set, 300) == 1);
    
    printf("Hash collision test passed!\n");
    freeHashSet(set);
}

int main() {
    printf("Running HashSet tests...\n\n");
    
    test_hashset_add();
    printf("\n");
    
    test_hashset_contains();
    printf("\n");
    
    test_hashset_remove();
    printf("\n");
    
    test_hashset_collision();
    printf("\n");
    
    printf("All tests passed!\n");
    
    return 0;
}