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
define( 'AUTH_KEY',         ':kXCCrbxjP MSRb_IW|MHk`$jWh.owtW~0|Q$<:RhscnuT;1GAUZ@TtiDGALfFRw' );
define( 'SECURE_AUTH_KEY',  'uR_m>bo7}m{GZEU$~@MaP&f-1K6L9_@%B)OILQCHA}wtkT~@fcs6)hFv!R/3{QZA' );
define( 'LOGGED_IN_KEY',    'E=.,WR<3mPOoL|td|ksb,l%lGq5+5KhW*C^XeH^uAp;`b,SG?W^2?X2@H!n&z7.2' );
define( 'NONCE_KEY',        ',5q{]UfuC86]|#--lE__8ojCUY5jQM1EiAwz}[VXmm;?L%@L/8Coo)8o$j<t~FIo' );
define( 'AUTH_SALT',        'zh?W2 nU&[uS9<YgaOQz@*KC6%y>M3Of,bR)N,Ab`xAjgMaZjRH=)<)rhN,&T$)U' );
define( 'SECURE_AUTH_SALT', 'C}gTz$5Q&~IogVeip9*ulq6a,u..7J%y95|M7zk]gx3QW9gMjmBa(3_O|k=_mU|$' );
define( 'LOGGED_IN_SALT',   'J&MBFBVOb1Gf1HYE@<D#s:1;--^f7*[~w&1$NzXll%`g4GQ&k]MVI}]n2ZiF*Jl<' );
define( 'NONCE_SALT',       'iF0D<[&vW//EbaXNoxQJ;|GP3v}Pz06|yrhlZQWz_+j[VyP&/0O:avdEaX2UTd!E' );

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
