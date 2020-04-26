int odwiedzony[100];

int graf::liczbaskladowychspojnych(){
	int v;
	for(v=0;v<100;++v){
		odwiedzony[v]=0;
	}
	int licznik=0;
	for(v=0;v<100;++v){
		if(odwiedzony[v]==0){
			++licznik;
			DFSnco(v);
		}
	}
	return licznik;
}

void graf::wypiszskladowespojne(){
	int v;
	for(v=0;v<100;++v){
		odwiedzony[v]=0;
	}
	int licznik=0;
	for(v=0;v<100;++v){
		if(odwiedzony[v]==0){
			++licznik;
			cout<<"skladowa"<<licznik<<endl;
			DFS(v);
		}
	}
}

void graf::DFSnco(int v){
	odwiedzony[v]=1;
	for(int u=0;u<100;++u){
		if(A[u][v]==1){
			if(odwiedzony[u]==0){
				DFSnco(u);
			}
		}
	}
}

void graf::DFS(int v){
	odwiedzony[v]=1;
	cout<<v<<endl;
	for(int u=0;u<100;++u){
		if(A[u][v]==1){
			if(odwiedzony[u]==0){
				DFS(u);
			}
		}
	}
}
