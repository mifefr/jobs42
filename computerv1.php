<?php
	if ($argc == 1)
	{
		print_r("Veuillez saisir une équation en paramétre.\n");
	}
	else if ($argc != 2)
	{
		print_r("Veuillez saisir une équation en un seul paramétre\n");
	}
	else
	{

													// gestion et distribution de l'equation \\
		$par = explode('=', $argv[1]);
		$str1 = '+ ' . trim($par[0]);
		preg_match_all('/[\+\-] ([\+\-]?[0-9\.]+) \* [xX]\^([0-9]+)/s', $str1, $m1, PREG_SET_ORDER);
		$q = 0;
		//print_r($m1);


		$par = explode('=', $argv[1]);
		$str2 = '+ ' . trim($par[1]);
		//echo "\n";
		preg_match_all('/[\+\-] ([\+\-]?[0-9\.]+) \* [xX]\^([0-9]+)/s', $str2, $m2, PREG_SET_ORDER);
		$q = 0;
		//print_r($m2);

															// gestion du degree \\
		$i = 0;
		$pui = 0;
		while ($m1[$i + 1])
			$i++;
		$pui = $m1[$i][2];
		$i = 0;
		while ($m2[$i + 1] && $m2[$i])
			$i++;
		if ($m2[$i] && $m2[$i][2] > $pui)
			$pui = $m2[$i][2];
		if ($pui == 0)
		{
			print("Tous les entiers sont solution !\n");
			exit (0);
		}
		if ($m1 == NULL)
		{
			print("Veuillez saisir une equation valab2le\n");
			exit(0);
		}
		$ok = conc($m1, $m2);
		$ok = reduct($ok, $pui);
		print("Reduced form: ");
		$ok = print_pol($ok);
		//print_r($ok);
		echo "Polynomial degree: ".$pui."\n";
		if ($pui > 2)
		{
			print_r("The polynomial degree is stricly greater than 2, I can't solve.\n");
			exit (0);
		}
		if ($pui == 2)
		{
			if ($ok[0][2] != 0 || $ok[1][2] != 1)
				$ok = addxo($ok);
			print_r($ok);
			resolvep2($ok);
		}
		else
			resolvep1($ok);

	}

																// reduction \\
	function reduct($s, $deg)
	{
		$pui = 0;
		while ($pui != $deg + 1)
		{
			$i = 0;
			$afonc = -1;
			while ($s[$i])
			{
				if ($afonc == -1 && $s[$i][2] == $pui)
					$afonc = $i;
				else if ($s[$i][2] == $pui)
				{
					if ($s[$i][0][0] == $s[$afonc][0][0])
						$s[$afonc][1] = $s[$afonc][1] + $s[$i][1];
					else
						$s[$afonc][1] = $s[$afonc][1] - $s[$i][1];
					$s[$i][2] = "null";
				}
				$i++;
			}
			$pui++;
		}
		$i = 0;
		while ($s[$i])
		{

			if ($s[$i][2] == "null" && $s[$i + 1] != NULL || $s[$i][1] == 0)
			{
				$s[$i] = $s[$i +1];
				$s[$i +1][2] = "null";
			}
			$i++;
		}
		$i = 0;
		while ($s[$i])
		{
			if ($s[$i][2] == "null")
				unset($s[$i]);
			$i++;
		}
		return ($s);
	}
															 //  concaténation  \\
	function conc($s1, $s2)
	{
		$i = 0;
		$y = 0;
		$istock = 0;
		while ($s1[$i])
			$i++;
		$istock = $i;
		while ($s2[$y])
		{
			$s1[$i] = $s2[$y];
			if ($s1[$i][0][0] == '-')
				$s1[$i][0][0] = '+';
			else
				$s1[$i][0][0] = '-';
			$s2[$y] = NULL;
			$i++;
			$y++;
		}
		return ($s1);
	}
															// affichage de l'equation \\
	function print_pol($s1)
	{
		$i = 0;
		$ok;
		while ($s1[$i])
		{
			//if ($s1[$i][2] == 0)
			//	print ($s1[$i][0][0]." 1");
			//else 
			//	{
			if ($s1[$i][1] > 0)
				$ok = '+';
			else
				$ok = '-';
			if ($i == 0)
			{
					print($s1[$i][1]." * X^".$s1[$i][2]);
					$s1[$i][0] = $s1[$i][1]." * X^".$s1[$i][2];
			}
			else 	
			{
				if ($s1[$i][0][0] == $ok)
				{
					print(" ".$ok." ".$s1[$i][1]." * X^".$s1[$i][2]);
					$s1[$i][0] = $ok." ".$s1[$i][1]." * X^".$s1[$i][2];
				}
				else
				{
					print(" - ".$s1[$i][1]." * X^".$s1[$i][2]);
					$s1[$i][0] = "- ".$ok." ".$s1[$i][1]." * X^".$s1[$i][2];
				}
			}
			$i++;
		}
		print(" = 0\n");
		return ($s1);
	}

	function addxo($s)
	{
		if ($s[0][2] == 1)
		{
			$s[0][1] = 0;
			$s[0][2] = 0;
			$s[0][0] = "0 * X^0";
			$s[2] = $s[1];
			$s[1] = $s[0];
		}
		else if ($s[0][2] == 2)
		{
			$s[2] = $s[0];
			$s[0][1] = 0;
			$s[0][2] = 0;
			$s[0][0] = "0 * X^0";
			$s[1][1] = 0;
			$s[1][2] = 1;
			$s[1][0] = "0 * X^1";
		}
		else
		{
			$s[2] = $s[1];
			$s[1][1] = 0;
			$s[1][2] = 1;
			$s[1][0] = "0 * X^1";
		}
		return ($s);
	}
															// test de l'égalité \\
	function resolvep2($s)
	{
		$i = 0;
		while ($s[$i])
		{
			if ($s[$i][0][0] == '-' && $s[$i][1] > 0)
				$s[$i][1] = $s[$i][1] * -1;
			$i++;
		}
		if ($s[2][1] == 0)
		{
			print("Division par 0 impossible, arret du programme ( 0 * X^2 )\n");
			exit (0);
		}
		$i = 0;
		$delta = $s[1][1] * $s[1][1] - 4 * $s[2][1] * $s[0][1];
		if ($delta < 0)
			print("Discriminant is strictly negative, no solution\n");
		else if ($delta == 0)
		{
			print("Discriminant is strictly equal, unique solution :\n");
			$delta = ($s[1][1] * -1) / (2 * $s[2][1]);
			print ($delta."\n");
		}
		else
		{
			print("Discriminant is strictly positive, the two solutions are:\n");
			$delta = sqrt($delta);
			$a1 = ($s[1][1] * -1 - $delta) / (2 * $s[2][1]);
			$a2 = ($s[1][1] * -1 + $delta) / (2 * $s[2][1]);
			print($a1."\n");
			print($a2."\n");
		}
		exit(0);
	}

	function resolvep1($s)
	{
		if ($s[0][2] == 1)
			print("the solution is :\n0\n");
		else
		{
			$ok = $s[0][1] / $s[1][1];
			print ("the solution is :\n".$ok."\n");
		}
		exit (0);
	}
?>