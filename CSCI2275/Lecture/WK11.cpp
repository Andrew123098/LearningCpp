/* Dijkstras Algorithm:
 * Finds shortest path in a weighted graph
 * 
 * BFS:
 * Finds shortest path in an unweighted graph
 * 
 * DFS: 
 * Won't find shortest path in either weighted or unweighted graph.
 * 
 * 
 * Weighted Path Cost:
 * Sum of the edge weights from the start to the end on the path.
 * 
 * Dijkstras Approach:
 * Finds the shortest path from start to intermediate nodes. 
 * Builds up final solution from the solutions to smaller nodes.
 * 
 * Vertex: 
 * string key
 * vector <adjVertex>adj
 * bool solved // similar to visited. Vertex is solved when we find the min wieght path
 * int distance
 * vertex* parent
 * 
 * dijkstras(start,end){
 *  vertex *startV=search(start);
 *  vertex *endV=search(end);
 *  //get a pointer to start and end vertices
 *  startV->solved=true;
 *  startV->distance=0;
 *  vector<vertex> solved;
 *  solved.push_back(startV);
 *  while(!endV->solved){
 *      minDist=INT_MAX
 *      vertex* solvedV=NULL;
 *      for(int x=0; x<solved.size(); x++){
 *          vertex* s=&solved(x);
 *          for(int y=0; y<s.adj.size(); y++){ // Loop over eveyrthing that is adjacnt
 *              if(s.adj[y].v->solved == false){
 *                  dist = s->distance + s.adj[y].weight; //distance to parent + edge wieght
 *                  if(dist < minDistance){
 *                      solvedV = s.adj[y].v;
 *                      minDistance = dist;
 *                      parent = s; 
 *                  }
 *              }
 *          }
 *      }
 *  solvedV->distance = minDistance;
 *  solvedV->parent = parent;
 *  solvedV->solved = true;
 *  solved.push_back(solvedV);
 * }
 *  
 * 
 * 
 * 
 * }