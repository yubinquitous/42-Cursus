<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'mariadb' );

/** Database username */
define( 'DB_USER', 'yubchoi' );

/** Database password */
define( 'DB_PASSWORD', '1234' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'Y#_;bd`qO`5[ ZCDHg^G[gTdd%Z]lct5hT3g``1K(6kb~oVYTc? s;]t5Ijo93fa' );
define( 'SECURE_AUTH_KEY',  'w0=Ov{sbT_U/Bl(*Tq]PmyA1<*+l93r ? _&2m76Wt7S&b<zn,=#5_y:s[S $<oO' );
define( 'LOGGED_IN_KEY',    'K|Hi8=pQ$5>:,<>!$4)3hJGx0MF87c{T)-b$iyVZvg;P994DHijwW=*G$=Yp3}b;' );
define( 'NONCE_KEY',        '@k3NL>wOM~4&9BhYqv#y(](KA>lp!XgV5n>UQz#sI~ee6ttRdu#7+8k?kX40?=0L' );
define( 'AUTH_SALT',        '.!#oM1fnMbQ$r;VA97^<w]+oH9k!i]MDLR~mrln{0BI?#^B < g4CB<Su~GK@3XP' );
define( 'SECURE_AUTH_SALT', 'ak[ZVR)V.Le:TgXtz!IhggR5`&!S0s}+Y(2KEG`+Zg%|<~Y8Vcm:a+mjy4AIt(J7' );
define( 'LOGGED_IN_SALT',   'I}iwCG({#<@x4B$e$c(yJzG4}~|lp}-gDcVqBOWv yxm9Au6IAh-N8t(zC@$,l9B' );
define( 'NONCE_SALT',       ',lMtc[=OJ)ij!;*&}E:j]|A}c0/K,Hy)RdqlzRmnYJ3`Qx/?BcxjG-dNP]!+g2)X' );

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
