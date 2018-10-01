<?php
/**
 * @file
 * Checkbox field tests.
 */

/**
 * Helper function to generate checkbox FAPI elements.
 */
function _boostrap_elements_checkbox(&$form) {

  $form['checkbox'] = array(
    '#type' => 'fieldset',
    '#title' => t('Checkboxes'),
    '#description' => t('Example description'),
  );

  $form['checkbox']['default'] = array(
    '#type' => 'checkbox',
    '#title' => t('checkbox Default'),
    '#description' => t('Example description'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
  );

  $form['checkbox']['horizontal_inline'] = array(
    '#type' => 'checkbox',
    '#title' => t('checkbox Horizontal (Inline)'),
    '#description' => t('Example description'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type' => 'horizontal',
    '#title_grid' => array(
      'columns' => array(
        'md' => 3,
      ),
    ),
    '#element_grid' => array(
      'columns' => array(
        'md' => 6,
      ),
    ),
  );

  $form['checkbox']['horizontal_before'] = array(
    '#type' => 'checkbox',
    '#title' => t('checkbox Horizontal (Before)'),
    '#description' => t('Example description'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type' => 'horizontal',
    '#title_display' => 'before',
    '#title_grid' => array(
      'columns' => array(
        'md' => 3,
      ),
    ),
    '#element_grid' => array(
      'columns' => array(
        'md' => 9,
      ),
    ),
  );


  $form['checkbox']['horizontal_columns'] = array(
    '#type' => 'checkboxes',
    '#options' => array(
      1,2,3,4,5,6,7,8,9,10
    ),
    '#title' => t('checkboxes Horizontal (Columns)'),
    '#description' => t('Example description'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type' => 'horizontal',
    '#title_display' => 'hidden',
    '#element_columns' => array(
      'columns' => array(
        'md' => 3,
      ),
    ),
    '#title_grid' => array(
      'columns' => array(
        'md' => 3,
      ),
    ),
    '#element_grid' => array(
      'columns' => array(
        'md' => 9,
      ),
    ),
  );




  $form['checkbox']['inline'] = array(
    '#type' => 'checkbox',
    '#title' => t('checkbox Inline'),
    '#description' => t('Example description'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type' => 'inline',

  );

}
