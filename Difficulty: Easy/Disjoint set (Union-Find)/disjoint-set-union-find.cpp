/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if(par[x] == x) return x;
    return par[x] = find(par, par[x]);
    
}

void unionSet(int par[], int x, int z) {
    // add code here.
    int px = find(par, x);
    int pz = find(par, z);
    if(px == pz) return;
    par[px] = pz; // parent of parent[x] becomes parent[z]

}