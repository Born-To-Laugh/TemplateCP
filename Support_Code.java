#pragma GCC optimize("Ofast, unroll-loops, inline, fast-math")
#pragma GCC target("avx, avx2, fma")

{
    auto start = chrono::high_resolution_clock::now();
    // ur code
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "\n\n\n--------------------------------\n";
    cout << "Time elapsed: " << duration.count() << " ms\n";
}
{
    Disjoint_Set_Union
    Head_Set
    Union_Set
    Fenwick_Tree
    Segment_Tree
    Chairman_Tree
    Per_Trie
    PointUpd
    RangeUpd
    Operate
}
{
    __builtin_ctzll
}