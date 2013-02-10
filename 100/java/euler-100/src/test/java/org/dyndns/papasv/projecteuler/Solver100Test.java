package org.dyndns.papasv.projecteuler;

import static org.junit.Assert.*;

import java.math.BigDecimal;
import java.math.BigInteger;

import org.junit.Test;

public class Solver100Test {

	@Test
	public void should_match() {
		assertEquals(BigInteger.valueOf(15),Solver100.isMatch(BigInteger.valueOf(21)));
	}

	@Test
	public void should_not_match() {
		assertEquals(BigInteger.ZERO,Solver100.isMatch(BigInteger.valueOf(20)));
	}
	@Test
	public void should_not_match_One() {
		assertEquals(BigInteger.ZERO,Solver100.isMatch(BigInteger.valueOf(1)));
	}

}
