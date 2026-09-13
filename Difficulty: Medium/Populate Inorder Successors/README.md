<h2><a href="https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1">Populate Inorder Successors</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given a Binary Tree where every node has next pointer along with left and right, complete the function to populate the next pointer for all nodes. The next pointer for every node should point to the Inorder successor of the node.</span></p>
<ul>
<li><span style="font-size: 14pt;">You do not have to return or print anything. Just make changes in the root node given to you. </span></li>
<li><span style="font-size: 14pt;">The node having no in-order successor will be pointed to -1. You don't have to add -1 explicitly, the driver code will take care of this.</span></li>
</ul>
<p><span style="font-size: 14pt;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root[] = [10, 8, 12, 3]
<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/933074/Web/Other/blobid0_1787144587.png" alt="" width="265" height="226">
<strong>Output: </strong>3-&gt;8 8-&gt;10 10-&gt;12 12-&gt;-1
<strong>Explanation: </strong>The inorder of the above tree is3 8 10 12. So the next of node 3 points to 8, next of 8 to 10 and next of 10 to 12. Next of 12 to -1 as there is no inorder successor of 12.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root[] = [1, 2, 3]
<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/933074/Web/Other/blobid1_1787144587.png" alt="" width="227" height="253">
<strong>Output: </strong>3-&gt;2 2-&gt;1 1-&gt;-1<br><strong>Explanation: </strong>The inorder of the above tree is 3 2 1. So the next of node 3 is points to 2 , next of 2 to 1. And next of 1 to -1 as there is no inorder successor of 1.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1&lt;= no. of nodes &lt;=10<sup>5</sup><br>1&lt;= data of the node &lt;=10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Traversal</code>&nbsp;