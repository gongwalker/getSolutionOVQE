<?php
	
function php_getSolutionOVQE($a,$b,$c=0){
	$x1=0;
	$x2=0;
	$detal=0;
	if($a==0 && $b==0){
		return false;
	}
	if($a==0){
		$x1 = -1 * ($c/$b);
		return [$x1];
	}
	$detal = pow($b,2) - 4*$a*$c;

	if($detal == 0){
		$x1 = (-1*$b + sqrt($detal)) / (2 * $a);
       		 return [$x1];
	}else if($detal > 0){
		$x1 = (-1*$b + sqrt($detal)) / (2 * $a);
		$x2 = (-1*$b - sqrt($detal)) / (2 * $a);
		return [$x1,$x2];
	}
	return false;
}
$start_time = microtime(true);
echo '<pre>';
for($i = 1;$i<=1000000;$i++){
	$a = $i+2;
	$b = $i*3;
	$c = $i+6;
	$re = php_getSolutionOVQE($a,$b,$c);
	//var_dump($re);	
}
$end_time = microtime(true);
echo 'use time : '.($end_time-$start_time).' s';
exit;

