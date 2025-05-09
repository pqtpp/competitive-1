#pragma once
#include "segtree"
#include <bits/stdc++.h>
using namespace std;
using pointset_rangesum_ll=segtree<long long,[](long long a,long long b)->long long{return a+b;}, []()->long long{return 0LL;}>;