<h2><a href="https://www.geeksforgeeks.org/problems/find-all-possible-paths-from-top-to-bottom/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab">Grid Paths from Top to Bottom Corner</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18.6667px;">Given an <strong>n x m</strong> matrix <strong>mat[][]</strong>, find all possible paths from the top-left cell <strong>(0, 0)</strong> to the bottom-right cell <strong>(n-1, m-1)</strong>.</span></p>
<p><span style="font-size: 18.6667px;">From each cell, movement is restricted to two directions:</span></p>
<ul>
<li><span style="font-size: 18.6667px;">Right → (i, j+1)</span></li>
<li><span style="font-size: 18.6667px;">Down → (i+1, j)</span></li>
</ul>
<p><span style="font-size: 18.6667px;">Return all possible paths, where each path is represented as a list of matrix elements encountered along the way.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> mat[][] = [[1, 2, 3], [4, 5, 6]]
<strong>Output:</strong> [[1, 4, 5, 6], [1, 2, 5, 6], [1, 2, 3, 6]]
<strong>Explanation:</strong> There are 3 possible paths from cell (0,0) to (1,2).</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> mat[][] = [[1, 2], [3, 4]]
<strong>Output:</strong> [[1, 2, 4], [1, 3, 4]]
<strong>Explanation:</strong> There are 2 possible paths from cell (0,0) to (1,1).</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n, m &lt;= 10<sup>&nbsp;</sup><br>1 &lt;= mat[i][j] &lt;= n*m<br>n * m &lt; 20</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;<code>Backtracking</code>&nbsp;