#!/usr/bin/php
<?php
$i = 0;
$j = 0;
while ($i < 999)
{
	while($j < 99)
	{
		echo "X";
		$j = $j + 1;
	}
	echo "\n";
	$i = $j + $i + 1;
	$j = 0;
}
?>
