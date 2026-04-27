#include <gtest/gtest.h>
#include <BitWithProxy.hpp>


TEST(BitReadTest, ReadsCorrectlyFromUint8) {
    uint8_t storage = 0b10110010;
    Bit<uint8_t> b0(storage, 0);
    Bit<uint8_t> b1(storage, 1);
    Bit<uint8_t> b7(storage, 7);
    
    EXPECT_FALSE(static_cast<bool>(b0));
    EXPECT_TRUE(b1);
    EXPECT_TRUE(b7);
}

TEST(BitReadTest, WorksInBooleanContexts) {
    uint8_t val = 0b00000100;
    Bit<uint8_t> bit(val, 2);
    
    if (bit) { SUCCEED(); } else { FAIL(); }
    EXPECT_TRUE(bit && !Bit<uint8_t>(val, 0));
}

TEST(BitWriteTest, SetsBitToOne) {
    uint8_t storage = 0;
    Bit<uint8_t> bit(storage, 3);
    
    bit[0] = true;
    EXPECT_EQ(storage, 0b00001000);
}

TEST(BitWriteTest, SetsBitToZero) {
    uint8_t storage = 0b11111111;
    Bit<uint8_t> bit(storage, 3);
    
    bit[0] = false;
    EXPECT_EQ(storage, 0b11110111);
}

TEST(BitWriteTest, BoundaryIndices_Uint8) {
    uint8_t storage = 0;
    Bit<uint8_t> first(storage, 0);
    Bit<uint8_t> last(storage, 7);
    
    first[0] = true;
    last[0] = true;
    EXPECT_EQ(storage, 0b10000001);
}

TEST(BitProxyTest, DirectProxyAssignment) {
    uint32_t val = 0x00000000;
    BitProxy<uint32_t> proxy(val, 15);
    
    proxy = true;
    EXPECT_EQ(val, 0x00008000);
    proxy = false;
    EXPECT_EQ(val, 0x00000000);
}

TEST(BitProxyTest, AssignmentFromBitToBit) {
    uint8_t src = 0b10101010;
    uint8_t dst = 0b00000000;
    Bit<uint8_t> bit_src(src, 3);
    Bit<uint8_t> bit_dst(dst, 0);

    bit_dst[0] = static_cast<bool>(bit_src);
    
    EXPECT_EQ(dst, 0b00000001);
    EXPECT_EQ(src, 0b10101010); 
}

TEST(BitOperatorBracketTest, SubscriptReadAndWrite) {
    uint8_t storage = 0b10101010;
    Bit<uint8_t> bit(storage, 3);
    EXPECT_TRUE(bit[0]);
    bit[0] = false;
    EXPECT_EQ(storage, 0b10100010);
}

TEST(BitTest, WorksWithUint32) {
    uint32_t storage = 0xFFFFFFFF;
    Bit<uint32_t> bit(storage, 31);
    EXPECT_TRUE(bit);
    bit[0] = false;
    EXPECT_EQ(storage, 0x7FFFFFFF);
}

TEST(BitTest, WorksWithUint64) {
    uint64_t storage = 0x0000000000000000ULL;
    Bit<uint64_t> bit(storage, 63);
    bit[0] = true;
    EXPECT_EQ(storage, 0x8000000000000000ULL);
}

TEST(BitTest, MultipleBitsReadWriteRoundTrip) {
    uint8_t storage = 0;
    Bit<uint8_t>(storage, 4)[0] = true;
    Bit<uint8_t>(storage, 3)[0] = true;
    Bit<uint8_t>(storage, 2)[0] = false;
    Bit<uint8_t>(storage, 1)[0] = true;
    Bit<uint8_t>(storage, 0)[0] = false;
    
    EXPECT_EQ(storage, 0b00011010);
    
    EXPECT_FALSE(Bit<uint8_t>(storage, 0));
    EXPECT_TRUE(Bit<uint8_t>(storage, 1));
    EXPECT_FALSE(Bit<uint8_t>(storage, 2));
    EXPECT_TRUE(Bit<uint8_t>(storage, 3));
    EXPECT_TRUE(Bit<uint8_t>(storage, 4));
}

TEST(BitTest, IndependentStorageReferences) {
    uint8_t a = 0, b = 0;
    Bit<uint8_t> bit_a(a, 2);
    Bit<uint8_t> bit_b(b, 5);
    
    bit_a[0] = true;
    EXPECT_EQ(a, 0b00000100);
    EXPECT_EQ(b, 0);
    
    bit_b[0] = true;
    EXPECT_EQ(a, 0b00000100);
    EXPECT_EQ(b, 0b00100000);
}