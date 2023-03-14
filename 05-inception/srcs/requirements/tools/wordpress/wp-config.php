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
define( 'DB_HOST', 'localhost' );

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
define( 'AUTH_KEY',         '2kvfwCZ.!m#)2- PZ`[*#]T,?`f4[94q-G8gnCEq|D1hMgq^ `JR3[~MHQe:a7.w' );
define( 'SECURE_AUTH_KEY',  'l<&*)|C;|![waj> ji]&J]:}jn8%Zm4x82%2Xee<=*rDuIul>zFK1*%gsJ%-J?bp' );
define( 'LOGGED_IN_KEY',    ')M#O2!:%L:l.BZ?f4{B>|/ml`QfON7aWfp_I]ns>s*3-`8v@2ty0nHLdBC$RiqQ9' );
define( 'NONCE_KEY',        'b@/v-lp?0ziklR d#QbnU35[Rd#4mcP_C*rhkJU-4T*ESYGikk+pX4[g/QP+Qb=G' );
define( 'AUTH_SALT',        'eRkIkg{s,E%;}y<fZ=~)Q~d#$Q:{>R#Dz{m3}#Rsz[<-,/K|pErklz2Jl%-L|4A2' );
define( 'SECURE_AUTH_SALT', 'P8y99zl-B H&2R!mBNsB$#/@:^o,8y!|C8eAECfE|1(1n%C2: VQjvPyM0>paN8E' );
define( 'LOGGED_IN_SALT',   '4=y<Gx?zj}%0aa#?X4;8_sx>F8?b?N2 ,F,,a-[0Yk:*1!rI;V60,)R>N2J>vB/#' );
define( 'NONCE_SALT',       '%v(b.x.O#|oZE4=s[S|Z}k~yUAmaW9fY6YWTTtZ6Q6N+~t;PW}Gr(:J+aCM!=G;!' );

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
