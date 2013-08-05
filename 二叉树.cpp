/*

*/
int get_nodeNum(node *root)
{
    if(root == NULL) return 0;
    return get_nodeNum(root->left) + get_nodeNum(root->right) + 1;
}
int get_depth(node *root)
{
    if(root == NULL) return 0;
    int leftDepth = get_depth(root->left);
    int rightDepth = get_depth(root->right);
    return leftdepth > rightdepth ? (leftdepth + 1) : (rightdepth + 1);
}
void preOrderTraverse(node *root)
{
    if(root == NULL) return;
    visit()
}
//层次遍历 队列+bfs

queue <node * > q;
q.push(root);
while(!q.empty())
{
    node *p = q.front();
    q.pop();
    visit(p);
    if(p->left != NULL) q.push(p->left);
    if(p->right != NULL) q.push(p->right);

}
return;

