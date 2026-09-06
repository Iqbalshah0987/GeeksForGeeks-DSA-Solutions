<h2><a href="https://www.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1">Word Search - Count Occurrences with 4 Directions</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a 2D grid <strong>mat[][]</strong> of size <strong>n × m</strong> consisting of characters and a string <strong>word</strong>, find the total number of occurrences of the word in the grid. </span></p>
<ul>
<li><span style="font-size: 18px;">The word can be formed by moving to adjacent cells in four directions (up, down, left, right), and the path may bend at 90-degree turns. </span></li>
<li><span style="font-size: 18px;">Each cell can be used at most once in a single occurrence.</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>mat[][] = {{S,N,B,S,N},{B,A,K,E,A},{B,K,B,B,K},{S,E,B,S,E}}, word = "SNAKES"
<strong>Output: </strong>3
<strong>Explanation</strong>: The word "SNAKES" occurs 3 times in the matrix.<br></span><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/929335/Web/Other/blobid1_1780740361.png" width="172" height="121"> </pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>mat[][] = {{c,a,t},{a,p,c},{t,t,a}}, word = "cat"<br><strong>Output: </strong>3
<strong>Explanation</strong>: The word "cat" occurs 3 times in the matrix.<br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/929335/Web/Other/blobid2_1780740372.png" width="157" height="138"></span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n, m ≤ 50<br></span><span style="font-size: 18px;"><span style="font-size: 18px;">1 ≤ l ≤ 15,&nbsp;</span></span><span style="font-size: 18px;"> Where l is the length of the word.</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;