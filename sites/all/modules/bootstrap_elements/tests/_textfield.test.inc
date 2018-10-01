<?php

/**
 * @file
 * Textfield tests.
 */

/**
 * Helper function to generate textfield FAPI elements.
 */
function _boostrap_elements_textfield(&$form) {

  $form['textfield'] = array(
    '#type' => 'fieldset',
    '#title' => t('Textfields'),
  );

  $form['textfield']['default'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield Default'),
    '#description' => t('Default textfield with no additional parameters'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
  );

  $form['textfield']['sep1'] = array(
    '#markup' => '<hr><h2>Horizontal Forms</h2>'
  );

  $form['textfield']['horizontal_inline'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield Horizontal (Inline)'),
    '#description' => t('Example description'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type' => 'horizontal',
    '#title_grid' => array(
      'columns' => array(
        'md' => 4,
      ),
    ),
    '#element_grid' => array(
      'columns' => array(
        'md' => 6,
      ),
    ),
  );

  $form['textfield']['horizontal_before'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield Horizontal (Before)'),
    '#description' => t('Example description'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type' => 'horizontal',
    '#title_grid' => array(
      'columns' => array(
        'md' => 4,
      ),
    ),
    '#element_grid' => array(
      'columns' => array(
        'md' => 6,
      ),
    ),
  );

  $form['textfield']['horizontal_after'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield Horizontal (After)'),
    '#description' => t('Example description'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type' => 'horizontal',
    '#title_display' => 'after',
    '#title_grid' => array(
      'columns' => array(
        'md' => 4,
      ),
    ),
    '#element_grid' => array(
      'columns' => array(
        'md' => 6,
      ),
    ),
  );


  $form['textfield']['horizontal_full'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield Horizontal (Full Width Label)'),
    '#description' => t('Full width label, title_align is set to left to line up the label'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type' => 'horizontal',
    '#title_align' => 'left',
    '#title_grid' => array(
      'columns' => array(
        'md' => 12,
      ),
    ),
    '#element_grid' => array(
      'columns' => array(
        'md' => 6,
      ),
    ),
  );


  $form['textfield']['nowrap'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield (no wrappers)'),
    '#description' => t('Textfield with all wrappers removed.'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type' => 'horizontal',
    '#form_type_wrapper' => FALSE,
    '#form_group_wrapper' => FALSE,
    '#form_field_wrapper' => FALSE,
  );


  $form['textfield']['notypewrap'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield (no type wrapper)'),
    '#description' => t('Textfield with the form_type_wrapper removed.'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type' => 'horizontal',
    '#form_type_wrapper' => FALSE,
  );


  $form['textfield']['sep2'] = array(
    '#markup' => '<hr><h2>Inline Forms</h2>'
  );



  $form['textfield']['inline'] = array(
    '#type' => 'container',
    '#form_type' => 'inline'
  );

  $form['textfield']['inline']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type_wrapper' => FALSE,
    '#size' => 10
  );



  $form['textfield']['inline']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
    '#form_type_wrapper' => FALSE,
    '#size' => 10
  );


  $form['textfield']['inline']['button'] = array(
    '#type' => 'button',
    '#value' => t('Submit'),
  );

  $form['textfield']['tooltips'] = array(
    '#markup' => '<hr><h2>Tooltips & Popovers</h2>'
  );

  $form['textfield']['tooltips-title'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield Default'),
    '#description' => t('Standard textfield with a title tooltip'),
    '#title_tooltip' => array(
      'placement' => 'top',
      'title' => 'This is a tooltip'
    ),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
  );

  $form['textfield']['popover-title'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield Default'),
    '#description' => t('Standard textfield with a title tooltip'),
    '#title_popover' => array(
      'placement' => 'top',
      'title' => 'This is a popover',
      'content' => 'this is a popover content'
    ),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
  );

  $form['textfield']['tooltip-suffix'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield Default'),
    '#description' => t('Standard textfield with a tootip suffix'),
    '#suffix_tooltip' => array(
      'placement' => 'top',
      'title' => 'This is a tooltip',
    ),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
  );

  $form['textfield']['tooltip-prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield Default'),
    '#description' => t('Standard textfield with a tootip suffix'),
    '#prefix_tooltip' => array(
      'placement' => 'top',
      'title' => 'This is a tooltip',
    ),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
  );




  $form['textfield']['popover-prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield Default'),
    '#description' => t('Standard textfield with a prefix tooltip'),
    '#prefix_popover' => array(
      'placement' => 'top',
      'title' => 'This is a popover',
      'content' => 'this is a popover content'
    ),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
  );


  $form['textfield']['popover-suffix'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield Default'),
    '#description' => t('Standard textfield with a prefix tooltip'),
    '#suffix_popover' => array(
      'placement' => 'top',
      'title' => 'This is a popover',
      'content' => 'this is a popover content'
    ),
    '#attributes' => array(
      'placeholder' => t('Example placeholder'),
    ),
  );


  $form['textfield']['dob'] = array(
    '#type' => 'date',
    '#title' => t('Date of birth'),
    '#date_format' => 'd/m/Y',
    '#required' => TRUE,
    '#suffix_tooltip' => array(
      'title' => t('Max length: 10'),
      'placement' => 'top',
    ),
    '#default_value' => !empty($form_state['values']['dob']) ? $form_state['values']['dob'] : '',
    '#form_type' => 'horizontal',
    '#title_grid' => array(
      'columns' => array(
        'md' => 3
      )
    ),
    '#element_grid' => array(
      'columns' => array(
        'md' => 5
      )
    ),
  );


  $form['textfield']['your_industry'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Industry'),
    '#options_selected_max' => 5,
    '#options_selected_min' => 0,
    '#title_tooltip' => array(
      'title' => t('Choose a maximum of 5'),
      'placement' => 'top',
    ),
    '#options' => array('1','2','3','4','5','6','7','8','9'),
    '#default_value' => !empty($form_state['values']['your_industry']) ? $form_state['values']['your_industry'] : '',
    '#form_type' => 'horizontal',
    '#title_grid' => array(
      'columns' => array(
        'md' => 3
      )
    ),
    '#element_grid' => array(
      'columns' => array(
        'md' => 7
      )
    ),
  );

}
