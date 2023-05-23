int l=0, r=MAXV;
while(r-l>1) {
	int m=(l+r)/2;
	if(go(m)) l=m;
	else r=m;
}
