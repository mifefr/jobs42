#!/usr/bin/php
<?php

while (true)
{
	echo "Entrez un nombre: ";
	$maman = fgets(STDIN);
	$maman = trim($maman);
	if (is_numeric($maman))
	{
		$i = 0;
		while ($maman[$i + 1])
			$i++;
		if ($maman[$i]%2)
			echo "le chiffre ".$maman." est Impair";
		else
			echo "le chiffre ".$maman." est Pair";
	}
	else
	{
		if (feof(STDIN))
			break ;
		echo "'".$maman."'"." n'est pas un chiffre";
	}
	echo "\n";
}
echo "\n";
?>